#include <string>

//
// Created by anton on 8/2/19.
//

#ifndef CURRENCY_BITT_API_H
#define CURRENCY_BITT_API_H

const std::string C_GET_MARKETS = "https://api.bittrex.com/v3/markets/";

const std::string C_MARKETS = "https://api.bittrex.com/v3/markets/";

const std::string C_SUMMARY = "summary";

const std::string C_BTC_USD = "BTC-USD";
const std::string C_ETH_USD = "ETH-USD";
const std::string C_LTC_USD = "LTC-USD";

// Candles for 1 year per everyday
extern char* C_BTC_USD_DAY_1;

#endif //CURRENCY_BITT_API_H
