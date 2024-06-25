import Foundation

protocol ISort {
    func sort() -> Int
    func name() -> String
}

class SortBase: ISort {
    var doubleArray: [Double]
    var size: Int

    init(size: Int) {
        self.size = size
        self.doubleArray = [Double](repeating: 0.0, count: size)
        for i in 0..<size {
            self.doubleArray[i] = Double(arc4random()) / Double(UInt32.max) * 1000000.0
        }
    }

    func sort() -> Int {
        let start = Date()
        sortImpl()
        let end = Date()
        return Int(end.timeIntervalSince(start) * 1000)  // Convert seconds to milliseconds
    }

    func sortImpl() {
        fatalError("sortImpl() must be overridden")
    }

    func name() -> String {
        fatalError("name() must be overridden")
    }
}

class MergeSort: SortBase {
    override func name() -> String {
        return "MergeSort"
    }

    override func sortImpl() {
        mergeSort(&self.doubleArray, 0, self.doubleArray.count - 1)
    }

    private func mergeSort(_ arr: inout [Double], _ l: Int, _ r: Int) {
        if l < r {
            let m = l + (r - l) / 2
            mergeSort(&arr, l, m)
            mergeSort(&arr, m + 1, r)
            merge(&arr, l, m, r)
        }
    }

    private func merge(_ arr: inout [Double], _ l: Int, _ m: Int, _ r: Int) {
        let n1 = m - l + 1
        let n2 = r - m

        var L = [Double](repeating: 0.0, count: n1)
        var R = [Double](repeating: 0.0, count: n2)

        for i in 0..<n1 {
            L[i] = arr[l + i]
        }
        for j in 0..<n2 {
            R[j] = arr[m + 1 + j]
        }

        var i = 0, j = 0, k = l
        while i < n1 && j < n2 {
            if L[i] <= R[j] {
                arr[k] = L[i]
                i += 1
            } else {
                arr[k] = R[j]
                j += 1
            }
            k += 1
        }

        while i < n1 {
            arr[k] = L[i]
            i += 1
            k += 1
        }

        while j < n2 {
            arr[k] = R[j]
            j += 1
            k += 1
        }
    }
}

func main() {
    // Main function equivalent in Swift
    let coll = MergeSort(size: 2000000)
    let dur = coll.sort()

    print("Sort took: \(dur) milliseconds")
}

main()
