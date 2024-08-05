## Hash Map basic operations we should know
Hash map should work with O(1) amortized with insert, check existance and remove.


### 1) Hash map Declaration
On python we use:

` hash_map = dict() `

On CPP we use:

`
#include <unordered_map><br/>
unordered_map<int, int> hash_map;
`

### 2) Hash map Initialization
On python we use:

` hash_map = {a: b, c: d} `<br/>

On CPP we use:

`#include <unordered_map>`<br/>
`unordered_map<int, int> hash_map = {{a, b}, {c, d}};`

### 3) Hash map basic operations
On python we use:

` hash_map[new_key] = new_value `<br/>
` del hash_map[new_key]  # No error raised if key not found`<br/>
` new_key in hash_map `<br/>

On CPP we use:

`#include <unordered_map>`<br/>
`hash_map[new_key] = new_value;`<br/>
`hash_map.erase(new_key); // No error raised if key not found`<br/>
`hash_map.find(new_key) != hash_map.end()`<br/>

