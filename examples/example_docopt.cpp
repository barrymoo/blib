#include <docopt/docopt.h>

static const std::string usage = R"(
crc-interactive.py -- An interactive Slurm helper
Usage: crc-interactive.py (-s | -g | -m) [-hv] [-t <time>] [-n <num-nodes>] [-p <partition>] [-c <num-cores>] [-u <num-gpus>] [-r <res-name>] [-b <memory>] [-a <account>]

Options:
  -s --smp                        Interactive job on smp cluster
  -g --gpu                        Interactive job on gpu cluster
  -m --mpi                        Interactive job on mpi cluster
  -h --help                       Print this screen and exit
  -v --version                    Print the version of crc-interactive.py
  -t --time <time>                Run time in hours, 1 <= time <= 12 [default: 1]
  -n --num-nodes <num-nodes>      Number of nodes [default: 1]
  -p --partition <partition>      Specify non-default partition
  -c --num-cores <num-cores>      Number of cores [default: 1]
  -u --num-gpus <num-gpus>        Used with -g only, number of GPUs [default: 1]
  -r --reservation <res-name>     Specify a reservation name
  -b --mem <memory>               Memory in GB
  -a --account <account>          Specify a non-default account)";

int main(int argc, const char **argv) {
    std::map<std::string, docopt::value> args = docopt::docopt(usage,
                                                               {argv + 1, argv + argc},
                                                               true,
                                                               "CRC Interactive 1.0");

    for (auto const &arg: args) {
        std::cout << arg.first << ": " << arg.second << '\n';
    }
};
