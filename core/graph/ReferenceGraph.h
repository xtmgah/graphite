#ifndef GRAPHITE_GRAPH_REFERENCEGRAPH_H
#define GRAPHITE_GRAPH_REFERENCEGRAPH_H

#include "GSSWGraph.h"
#include "core/reference/IReference.h"
#include "core/variant/IVariantList.h"
#include "core/allele/Allele.h"

#include "gssw.h"


namespace graphite
{
	class ReferenceGraph : public GSSWGraph
	{
	public:
		typedef std::shared_ptr< ReferenceGraph > SharedPtr;

	    ReferenceGraph(IReference::SharedPtr referencePtr, IVariantList::SharedPtr variantListPtr, Region::SharedPtr regionPtr, int matchValue, int misMatchValue, int gapOpenValue, int gapExtensionValue, uint32_t numGraphCopies);
		virtual ~ReferenceGraph();

		/* GSSWGraph::GSSWGraphMappingPtr traceBackAlignment(IAlignment::SharedPtr alignmentPtr); */

		void constructGraph() override;

	};
}

#endif //GRAPHITE_GR_GSSWGRAPHMANAGER_H
