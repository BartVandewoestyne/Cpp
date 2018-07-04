/*
 * Some guidelines for std::reduce from [brand20180515]:
 *
 *   - Use std::reduce when you want your accumulation to run in parallel.
 *   - Ensure that the operation you want to use is both associative and
 *     commutative.
 *   - Remember that the default initial value is produced by default
 *     construction, and that this may not be correct for your operation
 *
 * References:
 *
 *   [brand20180515] std::accumulate vs. std::reduce
 *     https://blog.tartanllama.xyz/accumulate-vs-reduce/
 */
