#ifndef EVALUATOR_HH
#define EVALUATOR_HH

#include <string>
#include <vector>

#include "random.hh"
#include "whiskertree.hh"
#include "fintree.hh"
#include "network.hh"
#include "problem.pb.h"
#include "answer.pb.h"
#include "outcome.hh"
#include "network.cc"
#include "rat-templates.cc"
#include "fish-templates.cc"

template <typename T>
class Evaluator {
private:
    const unsigned int _prng_seed;
    unsigned int _tick_count;

    std::vector< NetConfig > _configs;

    ProblemBuffers::Problem _ProblemSettings_DNA(void) const;

public:
    Evaluator(const ConfigRange & range);

    ProblemBuffers::Problem DNA(const T & actions) const;

    Outcome<T> score(T & run_actions,
            const bool trace = false,
            const double carefulness = 1) const;

    static Outcome<T> parse_problem_and_evaluate(const ProblemBuffers::Problem & problem);

    static Outcome<T> score(T & run_actions,
            const unsigned int prng_seed,
            const std::vector<NetConfig> & configs,
            const bool trace,
            const unsigned int ticks_to_run);
};


#endif
