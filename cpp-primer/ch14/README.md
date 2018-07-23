### LZ77

1. Lossless data compression algorithm
2. Published in 1977 by Abraham Lempel and Jacob Ziv
3. Variations: LZW, LZSS, LZMA and others



#### 核心概念

LZ77持有在未压缩数据流出现过的数据的单一拷贝，并且将重复出现的的同样数据替换成对这一份数据的引用，以 实现数据压缩的目的。



**匹配** 每一个匹配都被编码成(length, distance)对，<u>即长度为length的字符串中的每个字符与相同字符在未压缩的位置相差distance个字符。:question:</u>

**滑动窗口** 编码器追踪指定数量的最近数据，数量为`2KB`， `4KB` 或 `32KB`。
