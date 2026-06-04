char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Start with the first string as the prefix
    char* prefix = strs[0];
    int prefixLen = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Compare characters until mismatch or end of one string
        while (j < prefixLen && strs[i][j] == prefix[j]) {
            j++;
        }
        prefixLen = j; // shorten prefix length
        if (prefixLen == 0) {
            return ""; // no common prefix
        }
    }

    // Allocate memory for the result
    char* result = (char*)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';

    return result;
}