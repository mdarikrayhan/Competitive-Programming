import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.arraycopy
import java.lang.System.exit
import java.util.Arrays.copyOf
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.ArrayList
import java.util.NoSuchElementException
import java.util.StringTokenizer
object G {
internal var `in`:BufferedReader? = null
internal var out:PrintWriter? = null
internal var tok:StringTokenizer? = null
internal class IntList {
var data = IntArray(3)
var size = 0
fun size():Int {
return size
}
fun get(index:Int):Int {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
return data[index]
}
fun clear() {
size = 0
}
fun set(index:Int, value:Int) {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
data[index] = value
}
fun expand() {
if (size >= data.size)
{
data = copyOf(data, (data.size shl 1) + 1)
}
}
fun insert(index:Int, value:Int) {
if (index < 0 || index > size)
{
throw IndexOutOfBoundsException()
}
expand()
arraycopy(data, index, data, index + 1, size++ - index)
data[index] = value
}
fun delete(index:Int):Int {
if (index < 0 || index >= size)
{
throw IndexOutOfBoundsException()
}
var value = data[index]
arraycopy(data, index + 1, data, index, --size - index)
return value
}
fun push(value:Int) {
expand()
data[size++] = value
}
fun pop():Int {
if (size == 0)
{
throw NoSuchElementException()
}
return data[--size]
}
fun unshift(value:Int) {
expand()
arraycopy(data, 0, data, 1, size++)
data[0] = value
}
fun shift():Int {
if (size == 0)
{
throw NoSuchElementException()
}
var value = data[0]
arraycopy(data, 1, data, 0, --size)
return value
}
}
@Throws(Exception::class)
internal fun solve() {
var n = scanInt()
var m = scanInt()
var edges = arrayOfNulls<IntList>(n)
for (i in 0 until n)
{
edges[i] = IntList()
}
for (i in 0 until m)
{
var a = scanInt() - 1
var b = scanInt() - 1
if (a == b)
{
var s = edges[a]!!.size
edges[a]!!.push(b)
edges[a]!!.push(s + 2)
edges[a]!!.push(a)
edges[a]!!.push(s)
}
else
{
var sa = edges[a]!!.size
var sb = edges[b]!!.size
edges[a]!!.push(b)
edges[a]!!.push(sb)
edges[b]!!.push(a)
edges[b]!!.push(sa)
}
}
for (i in 0 until n)
{
if (edges[i]!!.size % 4 != 0)
{
out!!.println("NO")
return
}
}
var ans = ArrayList<IntList>()
var pos = IntArray(n)
var have = BooleanArray(n)
for (i in 0 until n)
{
while (pos[i] < edges[i]!!.size)
{
if (edges[i]!!.data[pos[i]] < 0)
{
pos[i] += 2
continue
}
var cans = IntList()
var cur = i
while (true)
{
if (have[cur])
{
var cans2 = IntList()
cans2.push(cur)
while (true)
{
var x = cans.pop()
if (x == cur)
{
break
}
have[x] = false
cans2.push(x)
}
cans2.push(cur)
ans.add(cans2)
}
cans.push(cur)
have[cur] = true
var next = edges[cur]!!.data[pos[cur]]
edges[cur]!!.data[pos[cur]] = -1
edges[next]!!.data[edges[cur]!!.data[pos[cur] + 1]] = -1
pos[cur] += 2
if (next == i)
{
break
}
while (edges[next]!!.data[pos[next]] < 0)
{
pos[next] += 2
}
cur = next
}
for (j in 0 until cans.size)
{
have[cans.data[j]] = false
}
cans.push(i)
ans.add(cans)
}
}
out!!.println("YES")
out!!.println(ans.size)
for (cans in ans)
{
out!!.print(cans.size)
for (i in 0 until cans.size)
{
out!!.print(" " + (cans.data[i] + 1))
}
out!!.println()
}
}
@Throws(IOException::class)
internal fun scanInt():Int {
return parseInt(scanString())
}
@Throws(IOException::class)
internal fun scanLong():Long {
return parseLong(scanString())
}
@Throws(IOException::class)
internal fun scanString():String {
while (tok == null || !tok!!.hasMoreTokens())
{
tok = StringTokenizer(`in`!!.readLine())
}
return tok!!.nextToken()
}
@JvmStatic fun main(args:Array<String>) {
try
{
`in` = BufferedReader(InputStreamReader(System.`in`))
out = PrintWriter(System.out)
solve()
`in`!!.close()
out!!.close()
}
catch (e:Throwable) {
e.printStackTrace()
exit(1)
}
}
}
fun main() {
G.main(arrayOf())
}