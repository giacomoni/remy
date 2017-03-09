/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "link_def.hh"
#include "stochastic-loss.hh"

template void Link::tick<Link>(Link& next, const double& tickno);
template void Link::tick<StochasticLoss>(StochasticLoss&, double const&);