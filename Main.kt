class NativeLib {
    init {
        System.loadLibrary("api")
    }
    external fun getInfoCurr(name: String): String
}

fun main() {
    println(NativeLib().getInfoCurr("btc"))
    println(NativeLib().getInfoCurr("eth"))
    println(NativeLib().getInfoCurr("ltc"))
}