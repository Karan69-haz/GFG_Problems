class Solution {
    countVowels(s, queries) {
        const vowels = new Set(['a', 'e', 'i', 'o', 'u'])
        const counts = [0]

        for (let i = 0; i < s.length; i++) counts.push(counts[i] + +vowels.has(s[i]))

        return queries.map(([l, r]) => counts[r + 1] - counts[l])
    }
}
