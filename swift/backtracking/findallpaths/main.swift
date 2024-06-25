import Foundation

class Node<T> {
    var val: T
    var children: [Node<T>]

    init(_ val: T, _ children: [Node<T>] = []) {
        self.val = val
        self.children = children
    }
}

func dfs(_ root: Node<Int>?, _ path: [String], _ res: inout [String]) {
    guard let root = root else { return }
    
    var path = path
    path.append(String(root.val))
    
    if root.children.isEmpty {
        res.append(path.joined(separator: "->"))
    } else {
        for child in root.children {
            dfs(child, path, &res)
        }
    }
}

func ternaryTreePaths(_ root: Node<Int>?) -> [String] {
    var res: [String] = []
    if let root = root {
        dfs(root, [], &res)
    }
    return res
}

// Helper function to build the tree from input
func buildTree<T>(_ iterator: inout Array<String>.Iterator, _ transform: (String) -> T) -> Node<T>? {
    guard let val = iterator.next(),
          let numChildrenStr = iterator.next(),
          let numChildren = Int(numChildrenStr) else {
        return nil
    }

    var children: [Node<T>] = []
    for _ in 0..<numChildren {
        if let child = buildTree(&iterator, transform) {
            children.append(child)
        }
    }
    return Node(transform(val), children)
}

// Helper function to get input words
func getWords() -> [String] {
    guard let line = readLine() else {
        return []
    }
    return line.components(separatedBy: .whitespacesAndNewlines).filter { !$0.isEmpty }
}

// Main function
func main() {
    let rootVec = getWords()
    var iterator = rootVec.makeIterator()
    if let root = buildTree(&iterator, { Int($0)! }) {
        let res = ternaryTreePaths(root)
        for line in res {
            print(line)
        }
    }
}

main()
