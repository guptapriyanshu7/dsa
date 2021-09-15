struct pair_hash {
  size_t operator () (pair<string, string> const& pair) const {
    return hash<string>()(pair.first + pair.second);
  }
};