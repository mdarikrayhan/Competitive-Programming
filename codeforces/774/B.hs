import qualified Data.ByteString.Lazy.Char8 as BS
import Data.List

type Cup = (Integer, Integer)

readInt :: BS.ByteString -> Integer
readInt x = case BS.readInteger x of Just (i, _) -> i
                                     Nothing -> error "Unparsable Int"

toPref :: [Cup] -> [Cup]
toPref ((x, y):(a, b):xs) = (x, y):toPref((a+x, b+y):xs)
toPref xs = xs

f :: Integer -> [Cup] -> [Cup] -> Integer
f _ _ [] = 0
f _ [] _ = 0
f k (x:xs) (y:ys) | (snd x) + (snd y) > k = f k (x:xs) ys
                  | otherwise = let now = (fst x) + (fst y)
                                  in max now $ f k xs (y:ys) 
cupCmp :: Cup -> Cup -> Ordering
cupCmp (a, b) (x, y) | a > x = GT
                     | x > a = LT
                     | a == x = if y > b then GT else LT

main = do
    (l:ls) <- fmap BS.lines BS.getContents
    let (n:m:k:[]) = map readInt $ BS.split ' ' l
        (as, bs) = splitAt (fromIntegral n) $ take (fromIntegral (n+m)) ls
        xs = map ((\[x, y] -> (x, y)) . map readInt . BS.split ' ') as
        ys = map ((\[x, y] -> (x, y)) . map readInt . BS.split ' ') bs
        xs' = reverse $ sortBy cupCmp xs
        ys' = reverse $ sortBy cupCmp ys
        xs'' = toPref xs'
        ys'' = reverse $ toPref ys'
     in print $ f k xs'' ys''