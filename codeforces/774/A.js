
var x = readline().split(" ").map( function (x) { return parseInt(x); } );
var n = 0, ans = -1;

for (var i = 0, str = readline(); i < str.length; i++)
    if (str.charAt(i) == '1') n++;

for (var i = 1; i <= n; i++) {
    var nm = parseInt(x[0] / i);
    var cost = (i - x[0] % i) * (x[1] + x[2] * Math.pow(nm - 1, 2)) +
        (x[0] % i) * (x[1] + x[2] * nm * nm);
    if (ans == -1 || cost < ans)
        ans = cost;
}

print(ans);
