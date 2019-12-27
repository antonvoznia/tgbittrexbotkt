//
// Created by anton on 8/10/19.
//

#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#ifndef CURRENCY_LOGS_H
#define CURRENCY_LOGS_H

const std::string C_CONN_PROBLEM = "Problem with connection!";
const std::string C_ANY_PROBLEM = "Problem to get data!";

const std::string log_file = "logs.txt";

void write_logs(std::string mess);

#endif //CURRENCY_LOGS_H
