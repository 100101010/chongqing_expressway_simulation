//
// Created by 帆桥 on 2019/6/28.
//

#ifndef CLIONCODE_OPTIMIZEHELP_HPP
#define CLIONCODE_OPTIMIZEHELP_HPP
namespace Utilt {
    class distance{
    private:
        int dist; // 距离
        int index; // 下标

    public:
        distance() = default;

        int getDist() const {
            return dist;
        }

        void setDist(int dist) {
            distance::dist = dist;
        }

        int getIndex() const {
            return index;
        }

        void setIndex(int index) {
            distance::index = index;
        }

        distance(int dist, int index) : dist(dist), index(index) {}

        bool operator>(const distance& ps) {
            return (dist>ps.dist? true: false);
        }

        bool operator>=(const distance& ps) {
            return (dist >= ps.dist? true: false);
        }

        bool operator==(const distance& ps) {
            return (dist == ps.dist? true: false);
        }

        bool operator<(const distance& ps) {
            return (dist < ps.dist? true: false);
        }
    };
}
#endif //CLIONCODE_OPTIMIZEHELP_HPP
