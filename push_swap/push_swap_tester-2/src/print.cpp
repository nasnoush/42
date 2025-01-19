//
// Created by Simon Cros on 13/01/2025.
//

#include <iostream>
#include <iomanip>

#include "complexity.hpp"

auto hideCursor() -> void
{
    if (prettyPrint())
    {
        std::cout << "\e[?25l";
    }
}

auto showCursor() -> void
{
    if (prettyPrint())
    {
        std::cout << "\e[?25h";
    }
}

auto getVersion() -> std::string_view
{
    return "Complexity 2.0.0 (2025-01-18)";
}

auto getUsage() -> std::string_view
{
    return "usage: ./complexity [-vh] [-s seed] [-f push_swap] [-t threads] numbers iterations [goal] [checker]";
}

auto getHelp() -> std::string
{
    return
        "\033[1mNAME\033[0m\n"
        "     \033[1mcomplexity\033[0m -- starting benchmark for push_swap\n"
        "\n"
        "\033[1mSYNOPSIS\033[0m\n"
        "     \033[1m./complexity\033[0m [\033[1m-vh\033[0m] [\033[1m-s\033[0m \033[4mseed\033[0m] [\033[1m-o\033[0m \033[4mfile\033[0m] [\033[1m-f\033[0m \033[4mfile\033[0m] [\033[1m-t\033[0m \033[4mthreads\033[0m] \033[4mnumbers\033[0m \033[4miterations\033[0m [\033[4mgoal\033[0m] [\033[4mchecker\033[0m]\n"
        "\n"
        "\033[1mDESCRIPTION\033[0m\n"
        "     Following options are available :\n"
        "     \n"
        "     \033[1m-v\033[0m, \033[1m--version\033[0m\n"
        "             Show version of tester\n"
        "     \n"
        "     \033[1m-h\033[0m, \033[1m--help\033[0m\n"
        "             Show this message\n"
        "     \n"
        "     \033[1m--json\033[0m, \033[1m--no-json\033[0m\n"
        "             Toggle JSON output on or off. By default, JSON output is enabled for non-TTY environments\n"
        "     \n"
        "     \033[1m-s\033[0m \033[4mseed\033[0m, \033[1m--seed\033[0m=\033[4mseed\033[0m\n"
        "             Generates the numbers based on the seed\n"
        "     \n"
        "     \033[1m-o\033[0m \033[4moutput\033[0m, \033[1m--output\033[0m=\033[4moutput\033[0m\n"
        "             Specifies an output file for logs\n"
        "     \n"
        "     \033[1m-f\033[0m \033[4mpush_swap\033[0m, \033[1m--file\033[0m=\033[4mpush_swap\033[0m\n"
        "             Use \033[4mpush_swap\033[0m for push_swap executable\n"
        "     \n"
        "     \033[1m-t\033[0m \033[4mthreads\033[0m, \033[1m--threads\033[0m=\033[4mthreads\033[0m\n"
        "             Specifies the amount of threads to use (default: 6)\n";
}

auto printStart(const program_opts& opts, const program_params& params, const ThreadSafeRandom::seed_type seed) -> void
{
    std::cout << getVersion() << '\n';
    std::cout << "\033[97mStarting the test : \033[95m" << params.numbers << "\033[97m elements, \033[95m" << params.iterations << "\033[97m iterations\033[0m" << " (seed " << seed << ")";
    std::cout << std::endl;
}

auto printStatus(const program_params& params, const results_t& results) -> void
{
    const status_t&& status = getStatus(params, results);

    std::cout << "Worst = \033[31m" << results.worst << "\033[0m instructions\033[K\n";
    std::cout << "Mean = \033[33m" << std::fixed << std::setprecision(1) << status.mean << "\033[0m instructions\033[K\n";
    std::cout << "Best = \033[36m" << results.best << "\033[0m instructions\033[K\n";
    std::cout << "Std. deviation = \033[93m" << std::fixed << std::setprecision(1) << status.stddev << "\033[0m instructions\033[K\n";

    if (params.objective.has_value()) {
        std::cout << "Objective = \033[94m" << status.underObjective
            << "\033[0m % under \033[94m" << params.objective.value()
            << "\033[0m (\033[91m" << results.aboveObjective << "\033[0m above)\033[K\n";
    } else {
        std::cout << "Objective = enter a number as the third argument\033[K\n";
    }

    // if (params.checker.has_value())
    //     std::cout << "Precision = \033[97m" << (ok * 100 / done) << "\033[0m % OK (\033[91m" << (done - ok) << "\033[0m KO)\033[K\n" << std::endl;
    // else
    //     std::cout << "Precision = enter a tester as the fourth argument\033[K\n";

    std::cout << "Failed = currently not available\033[K\n";
    std::cout << "\033[32m" << status.percentDone << "\033[0m % effective\033[K\n";
}

auto printJson(const program_params& params, const results_t& results, const ThreadSafeRandom::seed_type seed) -> void
{
    const status_t&& status = getStatus(params, results);

    std::cout << "{\n"
        << "  \"elements\": " << params.numbers << ",\n"
        << "  \"seed\": " << seed << ",\n"
        << "  \"iterations\": " << params.iterations << ",\n"
        << "  \"objective\": " << params.objective.value_or(-1) << ",\n"
        << "  \"worst\": " << results.worst << ",\n"
        << "  \"mean\": " << std::fixed << std::setprecision(6) << status.mean << ",\n"
        << "  \"best\": " << results.best << ",\n"
        << "  \"stddev\": " << std::fixed << std::setprecision(6) << status.stddev << ",\n"
        << "  \"aboveObjective\": " << results.aboveObjective << "\n"
        << "}\n";
}
