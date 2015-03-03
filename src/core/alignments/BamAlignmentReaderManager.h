#ifndef GWIZ_BAMALIGNMENTREADERMANAGER_H
#define GWIZ_BAMALIGNMENTREADERMANAGER_H

#include "IAlignmentReaderManager.h"

namespace gwiz
{
	class BamAlignmentReaderManager : public IAlignmentReaderManager
	{
	public:
		std::shared_ptr< BamAlignmentReaderManager > SharedPtr;

		BamAlignmentReaderManager(const std::string& bamPath);
		~BamAlignmentReaderManager();

	private:
		std::string m_bam_path;
	}
}

#endif //GWIZ_BAMALIGNMENTREADERMANAGER_H
