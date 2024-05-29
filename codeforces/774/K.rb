gets
puts gets.chomp.squeeze("aiuy").gsub(/e{3,}/, 'e').gsub(/o{3,}/, 'o')
