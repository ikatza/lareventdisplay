///////////////////////////////////////////////////////////////////////
///
/// \file   IWFHitDrawers.h
///
/// \brief  This provides an interface for tools which are tasked with
///         drawing the reconstructed hits on waveforms
///
/// \author T. Usher
///
////////////////////////////////////////////////////////////////////////

#ifndef IBaseline_H
#define IBaseline_H

#include "fhiclcpp/ParameterSet.h"
#include "larcoreobj/SimpleTypesAndConstants/RawTypes.h" // raw::ChannelID_t
#include "nutools/EventDisplayBase/View2D.h"
#include "TF1.h"

namespace evdb_tool
{
    class IWFHitDrawer
    {
    public:
        virtual ~IWFHitDrawer() noexcept = default;
        
        virtual void configure(const fhicl::ParameterSet& pset)       = 0;
        virtual void Draw(evdb::View2D&,
                          std::vector<std::unique_ptr<TF1>>&,
                          raw::ChannelID_t&)                    const = 0;
    };
}

#endif