// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 CCP - BusinessCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,      uint256("0x725d3c36854b8d811e53069b3e75c72d8108451f74ecd6b3924215b266f5b090"))
(1,      uint256("0x5cf74c866a45eaf7e55ff0fcb50c4e30e095b8b6248f240578e10c84332972a8"))
(100,    uint256("0xd3195c6d360a71579721ab470eba60da77845c87a723c93281b4e5fd3b9b5b7f"))
(1000,   uint256("0x9eadb13a1928a78c7b6b23ca608008fcbf8eb24214a9cd2fc7a3cda1a8925562"))
(55005,  uint256("0xd87543cf11347aa108bdf2e90de2263a1f11badcdafa76a34f0230b98efd10fe"))
(100501, uint256("0x3929fa5cbdb4bbabb3db69eed4439c696a2c71095933ad6bda57d9cb9f526bc0"))
(190613, uint256("0xcb574e27a46f77a4210b3788b8d5e021aec599f1469ca20daf88f6a9c966fc07"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
