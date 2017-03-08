/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   outcome.hh
 * Author: lg317
 *
 * Created on 08 March 2017, 10:24
 */

#ifndef OUTCOME_HH
#define OUTCOME_HH

#include <fcntl.h>
#include <string>
#include <vector>

#include "whiskertree.hh"
#include "fintree.hh"
#include "network.hh"
#include "protobufs/answer.pb.h"

 

template <typename T>
class Outcome {
public:
    double score;
    std::vector<std::pair<NetConfig,std::vector< std::pair< double, double > > > > throughputs_delays;
    T used_actions;

    Outcome() : score(0), throughputs_delays(), used_actions() {
    }

    Outcome(const AnswerBuffers::Outcome & dna);

    AnswerBuffers::Outcome DNA(void) const;
};



#endif /* OUTCOME_HH */

