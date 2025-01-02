a := File standardInput readLine asString
best := a
bestcount := 0
for (i, 0, a size - 1,
    for (j, i + 1, a size,
        sl := a slice(i, j)
        occ := a occurancesOfSeq(sl)
        if (occ > bestcount or (occ == bestcount and (sl size > best size or (sl size == best size and sl > best))),
            best = sl
            bestcount = occ
            )
        )
    )
best print