import com.beust.klaxon.Klaxon
import models.Currency
import java.util.*

class NativeLib {
    init {
        System.loadLibrary("api")
    }
    external fun getInfoCurr(name: String): String
}

fun createSummaryRes(btc: Currency?, eth: Currency?, ltc: Currency?): String {
    var mess = StringBuilder()
    mess.append("Current prices of the crypto-currencies: \n")
    mess.append(btc?.symbol).append(" ").append(btc?.high).append('\n')
    mess.append(eth?.symbol).append(" ").append(eth?.high).append('\n')
    mess.append(ltc?.symbol).append(" ").append(ltc?.high).append('\n')

    return mess.toString()
}

fun main(args: Array<String>) {
    val initNative = NativeLib()
    while (true) {
        val strBtc = initNative.getInfoCurr("btc")
        val strEth = initNative.getInfoCurr("eth")
        val strLtc = initNative.getInfoCurr("ltc")
        val res1 = Klaxon().parse<Currency>(strBtc)
        val res2 = Klaxon().parse<Currency>(strEth)
        val res3 = Klaxon().parse<Currency>(strLtc)
        val mess = createSummaryRes(res1, res2, res3)
        println(mess)
        Thread.sleep(10_000)
    }

}