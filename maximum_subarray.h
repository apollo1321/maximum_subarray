template<typename For>
// Requires Forward_iterator<For>()
auto find_maximum_subarray (For begin, For end)
{
    typename std::iterator_traits<For>::value_type max_sum_subarr = *begin;
    typename std::iterator_traits<For>::value_type max_sum        = *begin;

    For subarr_begin = begin;
    For left = begin;
    For right = ++begin;

    for (; begin != end; ++begin)
    {
        if (max_sum_subarr > 0)
            max_sum_subarr += *begin;
        else
        {
            max_sum_subarr = *begin;
            subarr_begin = begin;
        }

        if (max_sum_subarr > max_sum)
        {
            left = subarr_begin;
            right = begin;
            ++right;
            max_sum = max_sum_subarr;
        }
    }
    return make_tuple (left, right, max_sum);
}
