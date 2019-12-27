import com.beust.klaxon.Klaxon
import models.Currency
import tg.TelegramAPI

class NativeLib {
    init {
        System.loadLibrary("api")
    }
    external fun getInfoCurr(name: String): String
}

fun createSummaryRes(curr: MutableList<Currency?>): String {
    val correctInfo: (Currency?) -> StringBuilder = {y: Currency? ->
        StringBuilder().append(y?.symbol).append(" ").append(y?.high).append('\n')
    }
    var mess = StringBuilder()
    curr.iterator().forEach { mess.append(correctInfo(it)); }

    return mess.toString()
}

fun main(args: Array<String>) {

    val initNative = NativeLib()
    while (true) {
        val strBtc = initNative.getInfoCurr("btc")
        val strEth = initNative.getInfoCurr("eth")
        val strLtc = initNative.getInfoCurr("ltc")
        val l = mutableListOf<Currency?>()
        l.add(Klaxon().parse<Currency>(strBtc))
        l.add(Klaxon().parse<Currency>(strEth))
        l.add(Klaxon().parse<Currency>(strLtc))

        println(TelegramAPI.getUpdates())

        val mess = createSummaryRes(l)
        println(mess)
        Thread.sleep(10_000)
    }

}