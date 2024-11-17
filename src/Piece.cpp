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
        Piece(bool w, int v, PieceType pt): white(w), value(v), pieceType(pt){
            
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