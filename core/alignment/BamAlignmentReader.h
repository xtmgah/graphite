#ifndef GRAPHITE_BAMALIGNMENTREADER_HPP
#define GRAPHITE_BAMALIGNMENTREADER_HPP

#include "api/BamReader.h"
#include "api/BamAlignment.h"

#include "AlignmentReaderManager.hpp"
#include "core/region/Region.h"
#include "IAlignment.h"
#include "IAlignmentList.h"
#include "IAlignmentReader.h"
#include "Sample.hpp"


namespace graphite
{
	class BamAlignmentReader : public IAlignmentReader, public std::enable_shared_from_this< BamAlignmentReader >
	{
	public:
        typedef std::shared_ptr< BamAlignmentReader > SharedPtr;
        BamAlignmentReader(const std::string& bamPath);
		BamAlignmentReader(const std::string& bamPath, AlignmentReaderManager< BamAlignmentReader >* alignmentReaderManager);
		~BamAlignmentReader();

		void open() override;
		void close() override;

        std::vector< IAlignment::SharedPtr > loadAlignmentsInRegion(Region::SharedPtr regionPtr, bool excludeDuplicateReads = false) override;

		static std::vector< Sample::SharedPtr > GetBamReaderSamples(const std::string& bamPath);
		static position GetLastPositionInBam(const std::string& bamPath, Region::SharedPtr regionPtr);

		std::string getPath() { return m_bam_path; }
        uint32_t getReaderID() { return m_id; }

	private:
        AlignmentReaderManager< BamAlignmentReader >* m_alignment_reader_manager_ptr;

        BamTools::BamReader m_bam_reader;
		std::string m_bam_path;
		bool m_is_open;
		std::mutex m_lock;
	};
}

#endif //GRAPHITE_BAMALIGNMENTREADER_HPP
