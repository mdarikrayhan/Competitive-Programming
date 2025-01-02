[0[^ $$ 47> \58\> &]['0- \ 10*+]#%] r:

r;! n:   {read the number of elements in array}

0i:
[n;i;>]
[r;! i;1+i:]
#        {read the elements of the array}

1s:      {# of array copies stored in memory}

0i:
[n;1-i;>]
[ i;m:          {index of min element between i and n-1, inclusive}
  i;1+j:
  [n;j;>]
  [ n;m;-1- O   {extract a[m]}
    n;j;- O     {extract a[j], knowing that a[m] is on top}
    >
    [j;m:] ?    {if a[j] > a[m], m := j}
    j;1+j:
  ]#

  i;m;=~
  [ 0k:
    [n;k;>]
    [ k;e:     {index of element we're extracting now}
      k;i;=
         [m;e:] ?
      k;m;=
         [i;e:] ?
      n;k;+e;-1- O
      k;1+k:
    ]#
    s;1+s:      {+1 copy of array in memory}
  ] ?           {if i != m, copy all elements, while swapping a[i] and a[m]}
   
  i;1+i:]
#

0i:
[n;i;>]
[n;i;-1- O . " "
 i;1+i:]
#

0i:
[n;s;*i;>]
[% i;1+i:]
#