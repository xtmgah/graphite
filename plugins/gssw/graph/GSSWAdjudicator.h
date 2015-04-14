#ifndef GWIZ_GSSW_GSSWADJUDICATOR_H
#define GWIZ_GSSW_GSSWADJUDICATOR_H

#include "core/adjudicator/IGraphAdjudicator.h"
#include "GSSWGraph.h"

namespace gwiz
{
namespace gssw
{
	class GSSWAdjudicator : public IGraphAdjudicator
	{
	public:
		typedef std::shared_ptr< GSSWAdjudicator > SharedPtr;
		GSSWAdjudicator();
		~GSSWAdjudicator();

		IVariantList::SharedPtr adjudicateGraph(IGraph::SharedPtr graphPtr, IAlignmentReader::SharedPtr alignmentsPtr) override;
	private:
		void printNodes(GSSWGraph::SharedPtr graphPtr, const std::string& alignment);
	};
}
}

#endif //GWIZ_GSSW_GSSWADJUDICATOR_H