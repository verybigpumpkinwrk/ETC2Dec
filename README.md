# ETC2Dec

This is a WIP fast SIMD ETC1/ETC2 software decoder for decoding ETC1/ETC2 texture data on x86/x64 (currently) platforms.

## Status

* ETC1 RGB fully implemented
* ETC2 RGB I/D/P modes are optimized, T and H modes decoded using non vectorized reference decoder

### Notes

* Decoder writes all its data using 16 byte SSE writes, so (since 4 line RGB is 12 bytes) you need either to make a proper stride for your rows or change code to handle last block in a row write
* Requires SSE2 and SSSE3 (due to extensive use of pshufb) SIMD extensions support

#### Performance

Decoder |	ETC2Dec |	etcpack
------- | ------- | -------
2K ETC1 tex |	2.62ms |	22.5ms
2K ETC2 tex |	3.02ms |	22.56ms
4K ETC1 tex |	13.10ms |	89.90ms
4K ETC2 tex |	16.3ms |	89.5ms
3008x1904 ETC2 photo |	5.5ms |	31.4ms
