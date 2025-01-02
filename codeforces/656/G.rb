n,kitten,t=gets.split
p n.to_i.times.map{gets.chars}.transpose.count{|x|x.count('Y')>=t.to_i}
