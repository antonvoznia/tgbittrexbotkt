package tg

import java.net.URL

class TelegramAPI {
    companion object {
        val TELEGRAM_API: String = "https://api.telegram.org/bot<>/"
        val TELEGRAM_GET_UPDATES = "getUpdates"

        fun getUpdates(): String {
            val url = URL(TELEGRAM_API+ TELEGRAM_GET_UPDATES)
            val res = url.readText()
            return res
        }
    }
}