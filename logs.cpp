//
// Created by anton on 8/10/19.
//

#include "logs.h"
#include <iostream>

void write_logs(std::string mess) {
    std::ofstream out;
    auto curr_time = std::chrono::system_clock::now();
    const std::time_t time_error = std::chrono::system_clock::to_time_t(curr_time);
    out.open(log_file, std::ofstream::app);
    out << std::ctime(&time_error);
    out << mess << "\n\n";
    out.close();
}
