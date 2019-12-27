package models

class Currency(symbol: String, high: String, low: String, volume: String,
               baseVolume: String, quoteVolume: String, percentChange: String, updatedAt: String) {
    val symbol: String = symbol
    val high: String = high
    val low: String = low
    val volume: String = volume
    val baseVolume: String = baseVolume
    val quoteVolume: String = quoteVolume
    var percentChange: String = percentChange
    val updatedAt: String = updatedAt
}