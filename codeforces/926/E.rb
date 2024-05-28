

n = gets.to_i
rs = gets.split.map &:to_i

got = []
i = 0
j = 0

while i < n do
  if got.size == 0 then
    got.push(rs[i])
  elsif rs[i] == got[j] then
    got[j] += 1
    while j > 0 && got[j] == got[j-1] do
      j -= 1
      got[j] += 1
    end
  else
    if j == got.size - 1 then
      got.push(rs[i])
      j += 1
    else
      j += 1
      got[j] = rs[i];
    end
  end

  i += 1
end

p j+1
print got[0..j].join(' ')
