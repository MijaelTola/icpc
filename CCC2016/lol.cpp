
memset(dp, false, sizeof(dp));
  memset(sel, -1, sizeof(sel));
  dp[sz(S)] = true;
  for (int pos = sz(S) - 1; pos >= 0; pos--) {
    for (int idx: match[pos]) {
      if (dp[pos + sz(P[idx])]) {
//        assert(pos + sz(P[idx]) <= sz(S));
        dp[pos] = true;
        sel[pos] = idx;
        break;
      }
    }
  }
