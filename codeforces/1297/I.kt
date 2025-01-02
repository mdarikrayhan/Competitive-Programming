
import java.io.*
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov ([email protected])
 */
object programkt {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = TaskI()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskI {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            val n = `in`.readInt()
            val d = `in`.readInt()
            val l = IntArray(n)
            val r = IntArray(n)
            `in`.readIntArrays(l, r)
            MiscUtils.decreaseByOne(l)
            val h = IntArray(n + 1)
            val leftmost = IntArray(4 * d)
            val rightmost = IntArray(4 * d)
            val blocks = arrayOfNulls<IntList>(4 * d)
            for (i in blocks.indices) {
                blocks[i] = IntArrayList()
            }
            Arrays.fill(leftmost, n)
            Arrays.fill(rightmost, n)
            val query = object : TaskI.Query() {

                override fun query(root: Int, left: Int, right: Int, from: Int, to: Int): IntIntPair {
                    if (left >= from && right <= to) {
                        return IntIntPair(leftmost[root], rightmost[root])
                    }
                    if (left >= to || right <= from) {
                        return IntIntPair(n, n)
                    }
                    val mid = left + right shr 1
                    val l = query(2 * root + 1, left, mid, from, to)
                    val r = query(2 * root + 2, mid, right, from, to)
                    val cand = if (blocks[root]!!.isEmpty) n else blocks[root]!!.last()
                    if (h[cand] > h[l.first] && h[cand] > h[r.first]) {
                        return IntIntPair(cand, cand)
                    }
                    if (h[l.first] > h[r.first]) {
                        return l
                    }
                    return if (h[l.first] < h[r.first]) {
                        r
                    } else IntIntPair(l.first, r.second)
                }
            }
            val update = object : TaskI.Update() {
                private fun reeval(root: Int, left: Int, right: Int) {
                    leftmost[root] = if (blocks[root]!!.isEmpty) n else blocks[root]!!.last()
                    rightmost[root] = leftmost[root]
                    if (left + 1 < right) {
                        if (h[leftmost[2 * root + 1]] > h[leftmost[root]]) {
                            leftmost[root] = leftmost[2 * root + 1]
                            rightmost[root] = rightmost[2 * root + 1]
                        }
                        if (h[leftmost[2 * root + 2]] > h[leftmost[root]]) {
                            leftmost[root] = leftmost[2 * root + 2]
                            rightmost[root] = rightmost[2 * root + 2]
                        } else if (h[leftmost[2 * root + 2]] == h[leftmost[root]]) {
                            rightmost[root] = rightmost[2 * root + 2]
                        }
                    }
                }


                override fun update(root: Int, left: Int, right: Int, from: Int, to: Int, id: Int, add: Boolean) {
                    if (left >= from && right <= to) {
                        if (add) {
                            blocks[root]!!.add(id)
                        } else {
                            blocks[root]!!.popLast()
                        }
                        reeval(root, left, right)
                        return
                    }
                    if (left >= to || right <= from) {
                        return
                    }
                    val mid = left + right shr 1
                    update(2 * root + 1, left, mid, from, to, id, add)
                    update(2 * root + 2, mid, right, from, to, id, add)
                    reeval(root, left, right)
                }
            }
            var answer = 0
            for (i in 0 until n) {
                while (true) {
                    val res = query.query(0, 0, d, l[i], r[i])
                    if (res.first == n || l[res.first] < l[i] || r[res.second] > r[i]) {
                        h[i] = h[res.first] + 1
                        break
                    }
                    answer--
                    update.update(0, 0, d, l[res.first], r[res.first], res.first, false)
                }
                answer++
                update.update(0, 0, d, l[i], r[i], i, true)
                out.printLine(answer)
            }
        }

        internal abstract class Query {
            abstract fun query(root: Int, left: Int, right: Int, from: Int, to: Int): IntIntPair

        }

        internal abstract class Update {
            abstract fun update(root: Int, left: Int, right: Int, from: Int, to: Int, id: Int, add: Boolean)

        }

    }

    internal interface IntCollection : IntStream {

        val isEmpty: Boolean
            get() = size() == 0

        fun size(): Int

        open fun add(value: Int) {
            throw UnsupportedOperationException()
        }

        fun addAll(values: IntStream): IntCollection {
            val it = values.intIterator()
            while (it.isValid) {
                add(it.value())
                it.advance()
            }
            return this
        }

    }

    internal object MiscUtils {
        fun decreaseByOne(vararg arrays: IntArray) {
            for (array in arrays) {
                for (i in array.indices) {
                    array[i]--
                }
            }
        }

    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
            this.writer = PrintWriter(writer)
        }

        fun close() {
            writer.close()
        }

        fun printLine(i: Int) {
            writer.println(i)
        }

    }

    internal interface IntReversableCollection : IntCollection

    internal class IntIntPair(val first: Int, val second: Int) : Comparable<IntIntPair> {

        override fun equals(o: Any?): Boolean {
            if (this === o) {
                return true
            }
            if (o == null || javaClass != o.javaClass) {
                return false
            }

            val pair = o as IntIntPair?

            return first == pair!!.first && second == pair.second
        }

        override fun hashCode(): Int {
            var result = first
            result = 31 * result + second
            return result
        }

        override fun toString(): String {
            return "($first,$second)"
        }

        override fun compareTo(o: IntIntPair): Int {
            val value = Integer.compare(first, o.first)
            return if (value != 0) {
                value
            } else Integer.compare(second, o.second)
        }

    }

    internal interface IntIterator {

        val isValid: Boolean
        @Throws(NoSuchElementException::class)
        fun value(): Int

        fun advance(): Boolean

    }

    internal abstract class IntAbstractStream : IntStream {
        override fun toString(): String {
            val builder = StringBuilder()
            var first = true
            val it = intIterator()
            while (it.isValid) {
                if (first) {
                    first = false
                } else {
                    builder.append(' ')
                }
                builder.append(it.value())
                it.advance()
            }
            return builder.toString()
        }

        override fun equals(o: Any?): Boolean {
            if (o !is IntStream) {
                return false
            }
            val c = o as IntStream?
            val it = intIterator()
            val jt = c!!.intIterator()
            while (it.isValid && jt.isValid) {
                if (it.value() != jt.value()) {
                    return false
                }
                it.advance()
                jt.advance()
            }
            return !it.isValid && !jt.isValid
        }

        override fun hashCode(): Int {
            var result = 0
            val it = intIterator()
            while (it.isValid) {
                result *= 31
                result += it.value()
                it.advance()
            }
            return result
        }

    }

    internal interface IntStream : Iterable<Int>, Comparable<IntStream> {
        fun intIterator(): IntIterator

        override fun iterator(): Iterator<Int> {
            return object : Iterator<Int> {
                private val it = intIterator()

                override fun hasNext(): Boolean {
                    return it.isValid
                }

                override fun next(): Int {
                    val result = it.value()
                    it.advance()
                    return result
                }
            }
        }

        override fun compareTo(c: IntStream): Int {
            val it = intIterator()
            val jt = c.intIterator()
            while (it.isValid && jt.isValid) {
                val i = it.value()
                val j = jt.value()
                if (i < j) {
                    return -1
                } else if (i > j) {
                    return 1
                }
                it.advance()
                jt.advance()
            }
            if (it.isValid) {
                return 1
            }
            return if (jt.isValid) {
                -1
            } else 0
        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1024)
        private var curChar: Int = 0
        private var numChars: Int = 0
        private val filter: InputReader.SpaceCharFilter? = null

        fun readIntArrays(vararg arrays: IntArray) {
            for (i in 0 until arrays[0].size) {
                for (j in arrays.indices) {
                    arrays[j][i] = readInt()
                }
            }
        }

        fun read(): Int {
            if (numChars == -1) {
                throw InputMismatchException()
            }
            if (curChar >= numChars) {
                curChar = 0
                try {
                    numChars = stream.read(buf)
                } catch (e: IOException) {
                    throw InputMismatchException()
                }

                if (numChars <= 0) {
                    return -1
                }
            }
            return buf[curChar++].toInt()
        }

        fun readInt(): Int {
            var c = read()
            while (isSpaceChar(c)) {
                c = read()
            }
            var sgn = 1
            if (c == '-'.toInt()) {
                sgn = -1
                c = read()
            }
            var res = 0
            do {
                if (c < '0'.toInt() || c > '9'.toInt()) {
                    throw InputMismatchException()
                }
                res *= 10
                res += c - '0'.toInt()
                c = read()
            } while (!isSpaceChar(c))
            return res * sgn
        }

        fun isSpaceChar(c: Int): Boolean {
            return filter?.isSpaceChar(c) ?: isWhitespace(c)
        }

        interface SpaceCharFilter {
            fun isSpaceChar(ch: Int): Boolean

        }

        companion object {

            fun isWhitespace(c: Int): Boolean {
                return c == ' '.toInt() || c == '\n'.toInt() || c == '\r'.toInt() || c == '\t'.toInt() || c == -1
            }
        }

    }

    internal interface IntList : IntReversableCollection {
        operator fun get(index: Int): Int

        fun addAt(index: Int, value: Int)

        fun removeAt(index: Int)

        fun last(): Int {
            return get(size() - 1)
        }

        override fun intIterator(): IntIterator {
            return object : IntIterator {
                private var at: Int = 0
                private var removed: Boolean = false

                override val isValid: Boolean
                    get() = !removed && at < size()

                override fun value(): Int {
                    if (removed) {
                        throw IllegalStateException()
                    }
                    return get(at)
                }

                override fun advance(): Boolean {
                    at++
                    removed = false
                    return isValid
                }

                fun remove() {
                    removeAt(at)
                    at--
                    removed = true
                }
            }
        }

        override fun add(value: Int) {
            addAt(size(), value)
        }

        fun popLast() {
            removeAt(size() - 1)
        }

    }

    internal class IntArrayList : IntAbstractStream, IntList {
        private var size: Int = 0
        private var data = EMPTY

        @JvmOverloads
        constructor(capacity: Int = 3) {
            data = IntArray(capacity)
        }

        constructor(c: IntCollection) : this(c.size()) {
            addAll(c)
        }

        constructor(c: IntStream) : this() {
            if (c is IntCollection) {
                ensureCapacity(c.size())
            }
            addAll(c)
        }

        constructor(c: IntArrayList) {
            size = c.size()
            data = c.data.clone()
        }

        constructor(arr: IntArray) {
            size = arr.size
            data = arr.clone()
        }

        override fun size(): Int {
            return size
        }

        override fun get(at: Int): Int {
            if (at >= size) {
                throw IndexOutOfBoundsException("at = $at, size = $size")
            }
            return data[at]
        }

        private fun ensureCapacity(capacity: Int) {
            var capacity = capacity
            if (data.size >= capacity) {
                return
            }
            capacity = Math.max(2 * data.size, capacity)
            data = Arrays.copyOf(data, capacity)
        }

        override fun addAt(index: Int, value: Int) {
            ensureCapacity(size + 1)
            if (index > size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index)
            }
            data[index] = value
            size++
        }

        override fun removeAt(index: Int) {
            if (index >= size || index < 0) {
                throw IndexOutOfBoundsException("at = $index, size = $size")
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1)
            }
            size--
        }

        companion object {
            private val EMPTY = IntArray(0)
        }

    }
}

