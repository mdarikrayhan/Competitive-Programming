var n = readline().split(' ').map(function(v){return v;});
var arr = readline().split(' ').map(function(v){return v;});
arr.sort(function(a, b) {
  return a - b;
});
var g = 0;
var ans = 0;
for (var i = 1; i < n; i++) {
    g = gcd_rec(g, arr[i] - arr[i - 1]);
}
for (var i = 1; i < n; i++) {
    ans += ((arr[i] - arr[i - 1]) / g) - 1;
}
print(ans);

function gcd_rec(a, b) {
    if (b) {
        return gcd_rec(b, a % b);
    } else {
        return Math.abs(a);
    }
}