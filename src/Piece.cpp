#ifndef Piece_HH__
#define Piece_HH__

#include <climits>

namespace KS{

    /**
     * @authors Kaleb Gebrehiwot and Sofonias Gebre
     * @brief An abstract class to represent chess pieces
     */
    class Piece{
        public:
            const bool white;
            const int value;
            const PieceType pieceType;
            
            virtual void move() = 0;
            

        protected:
            Piece(bool white_, int value_, PieceType pieceType_): white(white_), value(value_), pieceType(pieceType_){
                
            }

    };
    enum PieceType{
        king,
        queen,
        bishop,
        knight,
        rook,
        pawn
    };

    //  --------------- Defining Pieces ------------------

    class Pawn : public Piece{
        public:
            Pawn(bool white_):
            Piece(white_, 1, PieceType::pawn){}

            void move() override{

            }
        private: 

    };

    class Bishop : public Piece{
        public:
            Bishop(bool white_):
            Piece(white_, 3, PieceType::bishop){}

        private:

    };

    class Knight : public Piece{
        public:
            Knight(bool white_):
            Piece(white_, 3, PieceType::knight){}
            
        private:

    };

    class Rook : public Piece{
        public:
            Rook(bool white_):
            Piece(white_, 5, PieceType::rook){}
            
        private:

    };

    class Queen : public Piece{
        public:
            Queen(bool white_):
            Piece(white_, 9, PieceType::queen){}
            
        private:

    };

    class King : public Piece{
        public:
            King(bool white_):
            Piece(white_, INT_MAX, PieceType::king){}
            
        private:
            bool hasMoved = false;
    };
}

#endif