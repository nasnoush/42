#include "complexity.hpp"

#include <iostream>

#include <version>

#include <getopt.h>

static auto parseNumber(const char* str, const int min) -> uint32_t
{
    size_t end;
    long number;

    try
    {
        number = std::stol(str, &end);
        if (str[end] != '\0')
            throw std::invalid_argument("");
    }
    catch (...)
    {
        throw std::invalid_argument(std::string() + str + " is not a valid number");
    }

    if (number < min)
        throw std::invalid_argument(std::string() + str + " must be at least equal to " + std::to_string(min));
    return number;
}

#define VALUE_JSON 1
#define VALUE_NO_JSON 2

auto getOptions(int& argc, char**& argv) -> program_opts
{
    static option long_options[] = {
        {"version", no_argument, nullptr, 'v'},
        {"help", no_argument, nullptr, 'h'},
        {"output", required_argument, nullptr, 'o'},
        {"file", required_argument, nullptr, 'f'},
        {"seed", required_argument, nullptr, 's'},
        {"threads", required_argument, nullptr, 't'},
        {"json", no_argument, nullptr, VALUE_JSON},
        {"no-json", no_argument, nullptr, VALUE_NO_JSON},
        {nullptr, 0, nullptr, 0}
    };

    program_opts opts{};

    int ch;
    while ((ch = getopt_long(argc, argv, "vhs:f:o:t:", long_options, nullptr)) != -1)
    {
        switch (ch)
        {
        case 'v':
            opts.version = true;
            break;
        case 'h':
            opts.help = true;
            break;
        case 'f':
            opts.program = optarg;
            break;
        case 'o':
            opts.output = optarg;
            break;
        case 't':
            opts.threads = parseNumber(optarg, 1);
            break;
        case 's':
            opts.seed = parseNumber(optarg, 0);
            break;
        case VALUE_JSON:
            opts.json = true;
            break;
        case VALUE_NO_JSON:
            opts.noJson = true;
            break;
        default:
            opts.usage = true;
        }
    }
    argc -= optind;
    argv += optind;

    return opts;
}

auto getParameters(const int argc, char** argv) -> program_params
{
    program_params params;

    if (argc < 2 || argc > 4)
        throw std::invalid_argument("");
    params.numbers = parseNumber(argv[0], 0);
    params.iterations = parseNumber(argv[1], 1);
    if (argc >= 3)
        params.objective = parseNumber(argv[2], 0);
    if (argc >= 4)
        params.checker = argv[3];
    return params;
}
