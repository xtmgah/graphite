#ifndef GRAPHITE_ASCIIFILEREADER_H
#define GRAPHITE_ASCIIFILEREADER_H

#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include <map>

#include <iostream>   // for std::cout
/* #include <boost/iostreams/device/mapped_file.hpp> // for mmap */
#include <fstream>

#include "IFile.h"

namespace graphite
{

	class ASCIIFileReader : public IFile
	{
	public:
		typedef std::shared_ptr< ASCIIFileReader > SharedPtr;
		ASCIIFileReader(const std::string& path);
		~ASCIIFileReader() override;

		/*
		 * Opens (and sets the size of the file) the file using
		 * the constructor's path. If the file does not exist
		 * then an exception is thrown.
		 */
		virtual void Open() override;
		/*
		 * Closes the opened file. If the file is not
		 * opened then this function does nothing.
		 */
		void Close() override;

		inline bool getNextLine(std::string& line) override
		{
			return (this->m_opened && std::getline(*this->m_file, line));
			/*
			const char* char_line = static_cast< const char* >(memchr(this->m_current_position, '\n', (this->m_end_file_ptr - this->m_current_position)));
			size_t lineSize = (char_line - this->m_current_position);
			line = std::string(this->m_current_position, lineSize); // subtract off the \n char
			this->m_current_position += lineSize + 1;
			return true;
			*/
		}

		void setFilePosition(uint64_t pos) override;

	protected:
		/* std::shared_ptr< boost::iostreams::mapped_file > m_file; */
		std::shared_ptr< std::ifstream > m_file;
		const char* m_start_position;
		const char* m_end_position;
		const char* m_current_position;

		const char* m_end_file_ptr;
	};

} // end namespace graphite

#endif //GRAPHITE_ASCIIFILEREADER_H
