#include <stack>
#include "ParserState.h"
#include "Parser.h"

bool Parser::parse(Token& tok)
{
    do {
        ParserState stateTop = stackSLR_.top();
        ParserState action = table_.action(stateTop, tok);

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
            stackSLR_.push(table_.goToState(stateTop, prodHead));
        } else if (action.isAccept()) {
            break; // acceptance reached
        } else if (action.isError()) {
            return false; // return false on syntax error
        }
    } while(1);

    return true;
}
