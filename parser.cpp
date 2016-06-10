#include <stdlib>
#include <map>

using namespace std;

class ParserState {
public:
    enum state_type_t { SHIFT, REDUCE, ACCEPT, ERROR };

    int prodSiz() { return prodSiz_; }

    string& prodHead() { return prodHead_; }

    state_type_t type() { return type_; }

    bool isShift() { return type_ == SHIFT; }

    bool isReduction() { return type_ == REDUCE; }

    bool isAccept() { return type_ == ACCEPT; }

    bool isError() { return type_ == ERROR; }

private:
    state_type_t type_;
    int prodSiz_;
    string prodHead_;
};

class ParserTable {
public:
    ParserTable() = default;
    ~ParserTable() = default;

    ParserState action(Token& tok)
    {
    }

    ParserState goToState(string& head)
    {
    }
private:
    map< pair<ParserState, int>, ParserState > table_;
};

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    bool parse(Token& tok)
    {
        do {
            ParserState stateTop = stackSLR_.top();
            ParserState action = stateTop.action(tok);

            if (action.isShift()) {
                stackSLR_.push(action);
                break; // get next token
            } else if (action.isReduction()) {
                // pop number of symbols of the reduction from the stack
                for(int i = 0; i < action.prodSiz(); ++i)
                    stackSLR_.pop();
                // prodHead is the head of the reduction
                string prodHead = action.prodHead();
                // stateTop is now the state on the top of the queue
                stateTop = stackSLR_.top();
                // push goto[stateTop, prodHead] to the stack
                stackSLR_.push(stateTop.goToState(prodHead));
            } else if (action.isAccept()) {
                break; // acceptance reached
            } else if (action.isError()) {
                return false; // return false on syntax error
            }
        } while(1);

        return true;
    }
private:
    stack<ParserState> stackSLR_;
};

int main()
{
    Parser p;
    Token t;

    while(t = getToken(stream)) {
        p.parse(t);
    }
    p.parse(); // pass end-of-input token

    return 0;
}
