
// 正确 不完全类型
struct s {
	struct t *pt;
};
struct t {
	struct s *ps;
};

// 错误 不完全类型
struct s {
	struct t ot;
};
struct t {
	struct s os;
};

// 完全类型 常用数据结构 链表、二叉树的基本组成单元
struct s {
	char data[6];
	struct s* next;
};
