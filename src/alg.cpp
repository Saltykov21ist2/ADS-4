// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int s = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        s += 1;
    }
  }
  return s;
}
int countPairs2(int *arr, int len, int value) {
  int s = 0;
  int t;
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] > value) {
      continue;
    } else {
      t = i;
      break;
    }
  }
  for (int i = 0; i < t - 1; i++) {
    for (int j = t; j >= i + 1; j--) {
      if (arr[i] + arr[j] == value)
        s++;
    }
  }
  return s;
}
int countPairs3(int *arr, int len, int value) {
  int s = 0, ll = 0, rr = len - 1;
  while (ll < rr - 1) {
    int mm_1 = (ll + rr) / 2;
    if (arr[mm_1] <= value)
      ll = mm_1;
    else
      rr = mm_1;
  }
  len = rr - 1;
  for (int i = 0; i < len; i++) {
    ll = i + 1, rr = len - 1;
    int u = 0;
    while (ll < rr) {
      int mm_2 = (ll + rr) / 2;
      if (arr[mm_2] < (value - arr[i]))
        ll = mm_2 + 1;
      else
        rr = mm_2;
    }
    while (arr[ll] == (value - arr[i])) {
      u++;
      ll++;
    }
    s += u;
  }
  return s;
}

