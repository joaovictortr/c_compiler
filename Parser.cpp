#include "Parser.h"

Parser::Parser()
{
    // initialize stacks with start state and an empty token
    stateStack_.push(table_.startState());
    tokenStack_.push(pair<Token, string>(Token(), string()));
}

/**
 * Implements the SLR(1) parsing algorithm of one token
 * @param tok Token to be parsed
 * @return true if no error occurs, otherwise return false
 */
bool Parser::parse(Token &tok)
{
    do {
        // get the state on the top of the stack without popping
        ParserState stateTop = stateStack_.top();
        // lookup the action to be taken
        ParserState action = table_.action(stateTop, tok);
        if (action.isShift()) {
            stateStack_.push(action);
            tokenStack_.push(pair<Token, string>(tok, tok.strType()));
            break; // get next token
        } else if (action.isReduction()) {
            // pop number of symbols of the reduction from the stack
            for(int i = 0; i < action.prodSiz(); ++i) {
                stateStack_.pop();
                tokenStack_.pop();
            }
            // prodHead is the head of the reduction
            string prodHead = action.prodHead();
            // stateTop is now the state on the top of the queue
            stateTop = stateStack_.top();
            // push goto[stateTop, prodHead] to the stack
            stateStack_.push(table_.goToState(stateTop, prodHead));
            tokenStack_.push(pair<Token, string>(Token(), prodHead));
        } else if (action.isAccept()) {
            break; // acceptance reached
        } else if (action.isError()) {
            return false; // return false on syntax error
        }
    } while(1);

    return true;
}

