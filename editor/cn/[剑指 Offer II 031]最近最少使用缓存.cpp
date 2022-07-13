//
// 运用所掌握的数据结构，设计和实现一个 LRU (Least Recently Used，最近最少使用) 缓存机制 。 
//
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
// 
//
// 
//
// 进阶：是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 注意：本题与主站 146 题相同：https://leetcode-cn.com/problems/lru-cache/ 
// Related Topics 设计 哈希表 链表 双向链表 👍 55 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
private:
//定义一个双向链表
struct Node{
    int key;
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(){};
    Node(int key, int val) : key(key), val(val) {}
};
    int capacity = 0;
    //用两个节点表示，链表头部与链表尾部
    Node* head = nullptr, *tail = nullptr;
    // map 匹配键值 key 与 对应的链表节点
    unordered_map<int, Node*> ump;
public:
    LRUCache(int capacity) {
        tail = new Node();
        head = new Node();
        linkTwoNode(head, tail);
        this->capacity = capacity;
    }

    int get(int key) {
        if(ump.count(key)){
            //获取键值 key 对应的数据后，需要将其放在链表头部节点后
            put(key, ump[key]->val);
            return ump[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        Node* newNode = nullptr;
        if(ump.count(key)){
            ump[key]->val = value;
            newNode = ump[key];
            //存在当前键值 key 所表示的数据， 需要将其表示的来链表节点提前至头部节点后
            //连接当前节点的前后两个节点
            linkTwoNode(newNode->prev, newNode->next);
        }
        else{
            newNode = new Node(key, value);
            ump[key] = newNode;
            //容量超出预设，清除map容器的记录，且需要将尾部节点的前一个节点删掉，
            if(ump.size() > capacity){
                ump.erase(tail->prev->key);
                linkTwoNode(tail->prev->prev, tail);
            }
        }

        //将需要调整的节点(新节点或者是读取的旧节点)，提前到头节点尾部
        linkTwoNode(newNode, head->next);
        linkTwoNode(head, newNode);
    }
private:
    //连接链表前后两个节点
    void linkTwoNode(Node* preNode, Node* laterNode){
        preNode->next = laterNode;
        laterNode->prev = preNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
