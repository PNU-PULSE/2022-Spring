# leetcode 2166
# fix(idx) => idx에 있는 원소를 1로 변경
# unfix(idx) => idx에 있는 원소를 0으로 변경
# flip() => 0을 1로, 1을 0으로 변경
# all() => 모든 원소가 1이면 True 리턴, 아니면 False 리턴
# one() => 1이 하나라도 있으면 True 리턴, 아니면 False 리턴
# count() => 1갯수 count


class Bitset:
    bitset = []
    bit_num = 0

    def __init__(self, size: int):
        Bitset.bitset = [0]*size

    def fix(self, idx: int) -> None:
        Bitset.bitset[idx] = 1

    def unfix(self, idx: int) -> None:
        Bitset.bitset[idx] = 0

    def flip(self) -> None:
        for i in range(len(Bitset.bitset)):
            if Bitset.bitset[i] == 1:
                Bitset.bitset[i] = 0
            else:
                Bitset.bitset[i] = 1

    def all(self) -> bool:
        if 0 in Bitset.bitset:
            return False
        else:
            return True

    def one(self) -> bool:
        if 1 in Bitset.bitset:
            return True
        else:
            return False

    def count(self) -> int:
        return Bitset.bitset.count(1)

    def toString(self) -> str:
        bit_str = ""
        for i in Bitset.bitset:
            bit_str += str(i)
        return bit_str


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
