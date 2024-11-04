
// Generated from .\originirParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "originirParserListener.h"


/**
 * This class provides an empty implementation of originirParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  originirParserBaseListener : public originirParserListener {
public:

  virtual void enterTranslationunit(originirParser::TranslationunitContext * /*ctx*/) override { }
  virtual void exitTranslationunit(originirParser::TranslationunitContext * /*ctx*/) override { }

  virtual void enterDeclaration(originirParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(originirParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterQinit_declaration(originirParser::Qinit_declarationContext * /*ctx*/) override { }
  virtual void exitQinit_declaration(originirParser::Qinit_declarationContext * /*ctx*/) override { }

  virtual void enterCinit_declaration(originirParser::Cinit_declarationContext * /*ctx*/) override { }
  virtual void exitCinit_declaration(originirParser::Cinit_declarationContext * /*ctx*/) override { }

  virtual void enterQuantum_gate_declaration(originirParser::Quantum_gate_declarationContext * /*ctx*/) override { }
  virtual void exitQuantum_gate_declaration(originirParser::Quantum_gate_declarationContext * /*ctx*/) override { }

  virtual void enterIndex(originirParser::IndexContext * /*ctx*/) override { }
  virtual void exitIndex(originirParser::IndexContext * /*ctx*/) override { }

  virtual void enterC_KEY_declaration(originirParser::C_KEY_declarationContext * /*ctx*/) override { }
  virtual void exitC_KEY_declaration(originirParser::C_KEY_declarationContext * /*ctx*/) override { }

  virtual void enterQ_KEY_declaration(originirParser::Q_KEY_declarationContext * /*ctx*/) override { }
  virtual void exitQ_KEY_declaration(originirParser::Q_KEY_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_without_parameter_declaration(originirParser::Single_gate_without_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_gate_without_parameter_declaration(originirParser::Single_gate_without_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_one_parameter_declaration(originirParser::Single_gate_with_one_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_one_parameter_declaration(originirParser::Single_gate_with_one_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_two_parameter_declaration(originirParser::Single_gate_with_two_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_two_parameter_declaration(originirParser::Single_gate_with_two_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_three_parameter_declaration(originirParser::Single_gate_with_three_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_three_parameter_declaration(originirParser::Single_gate_with_three_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_four_parameter_declaration(originirParser::Single_gate_with_four_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_four_parameter_declaration(originirParser::Single_gate_with_four_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterDouble_gate_without_parameter_declaration(originirParser::Double_gate_without_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitDouble_gate_without_parameter_declaration(originirParser::Double_gate_without_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterDouble_gate_with_one_parameter_declaration(originirParser::Double_gate_with_one_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitDouble_gate_with_one_parameter_declaration(originirParser::Double_gate_with_one_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterDouble_gate_with_four_parameter_declaration(originirParser::Double_gate_with_four_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitDouble_gate_with_four_parameter_declaration(originirParser::Double_gate_with_four_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterTriple_gate_without_parameter_declaration(originirParser::Triple_gate_without_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitTriple_gate_without_parameter_declaration(originirParser::Triple_gate_without_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterDefine_gate_declaration(originirParser::Define_gate_declarationContext * /*ctx*/) override { }
  virtual void exitDefine_gate_declaration(originirParser::Define_gate_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_gate_without_parameter_type(originirParser::Single_gate_without_parameter_typeContext * /*ctx*/) override { }
  virtual void exitSingle_gate_without_parameter_type(originirParser::Single_gate_without_parameter_typeContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_one_parameter_type(originirParser::Single_gate_with_one_parameter_typeContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_one_parameter_type(originirParser::Single_gate_with_one_parameter_typeContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_two_parameter_type(originirParser::Single_gate_with_two_parameter_typeContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_two_parameter_type(originirParser::Single_gate_with_two_parameter_typeContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_three_parameter_type(originirParser::Single_gate_with_three_parameter_typeContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_three_parameter_type(originirParser::Single_gate_with_three_parameter_typeContext * /*ctx*/) override { }

  virtual void enterSingle_gate_with_four_parameter_type(originirParser::Single_gate_with_four_parameter_typeContext * /*ctx*/) override { }
  virtual void exitSingle_gate_with_four_parameter_type(originirParser::Single_gate_with_four_parameter_typeContext * /*ctx*/) override { }

  virtual void enterDouble_gate_without_parameter_type(originirParser::Double_gate_without_parameter_typeContext * /*ctx*/) override { }
  virtual void exitDouble_gate_without_parameter_type(originirParser::Double_gate_without_parameter_typeContext * /*ctx*/) override { }

  virtual void enterDouble_gate_with_one_parameter_type(originirParser::Double_gate_with_one_parameter_typeContext * /*ctx*/) override { }
  virtual void exitDouble_gate_with_one_parameter_type(originirParser::Double_gate_with_one_parameter_typeContext * /*ctx*/) override { }

  virtual void enterDouble_gate_with_four_parameter_type(originirParser::Double_gate_with_four_parameter_typeContext * /*ctx*/) override { }
  virtual void exitDouble_gate_with_four_parameter_type(originirParser::Double_gate_with_four_parameter_typeContext * /*ctx*/) override { }

  virtual void enterTriple_gate_without_parameter_type(originirParser::Triple_gate_without_parameter_typeContext * /*ctx*/) override { }
  virtual void exitTriple_gate_without_parameter_type(originirParser::Triple_gate_without_parameter_typeContext * /*ctx*/) override { }

  virtual void enterPri_ckey(originirParser::Pri_ckeyContext * /*ctx*/) override { }
  virtual void exitPri_ckey(originirParser::Pri_ckeyContext * /*ctx*/) override { }

  virtual void enterPri_cst(originirParser::Pri_cstContext * /*ctx*/) override { }
  virtual void exitPri_cst(originirParser::Pri_cstContext * /*ctx*/) override { }

  virtual void enterPri_expr(originirParser::Pri_exprContext * /*ctx*/) override { }
  virtual void exitPri_expr(originirParser::Pri_exprContext * /*ctx*/) override { }

  virtual void enterConstant(originirParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(originirParser::ConstantContext * /*ctx*/) override { }

  virtual void enterUnary_expression(originirParser::Unary_expressionContext * /*ctx*/) override { }
  virtual void exitUnary_expression(originirParser::Unary_expressionContext * /*ctx*/) override { }

  virtual void enterMultiplicative_expression(originirParser::Multiplicative_expressionContext * /*ctx*/) override { }
  virtual void exitMultiplicative_expression(originirParser::Multiplicative_expressionContext * /*ctx*/) override { }

  virtual void enterAddtive_expression(originirParser::Addtive_expressionContext * /*ctx*/) override { }
  virtual void exitAddtive_expression(originirParser::Addtive_expressionContext * /*ctx*/) override { }

  virtual void enterRelational_expression(originirParser::Relational_expressionContext * /*ctx*/) override { }
  virtual void exitRelational_expression(originirParser::Relational_expressionContext * /*ctx*/) override { }

  virtual void enterEquality_expression(originirParser::Equality_expressionContext * /*ctx*/) override { }
  virtual void exitEquality_expression(originirParser::Equality_expressionContext * /*ctx*/) override { }

  virtual void enterLogical_and_expression(originirParser::Logical_and_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_and_expression(originirParser::Logical_and_expressionContext * /*ctx*/) override { }

  virtual void enterLogical_or_expression(originirParser::Logical_or_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_or_expression(originirParser::Logical_or_expressionContext * /*ctx*/) override { }

  virtual void enterAssignment_expression(originirParser::Assignment_expressionContext * /*ctx*/) override { }
  virtual void exitAssignment_expression(originirParser::Assignment_expressionContext * /*ctx*/) override { }

  virtual void enterExpression(originirParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(originirParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterControlbit_list(originirParser::Controlbit_listContext * /*ctx*/) override { }
  virtual void exitControlbit_list(originirParser::Controlbit_listContext * /*ctx*/) override { }

  virtual void enterStatement(originirParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(originirParser::StatementContext * /*ctx*/) override { }

  virtual void enterDagger_statement(originirParser::Dagger_statementContext * /*ctx*/) override { }
  virtual void exitDagger_statement(originirParser::Dagger_statementContext * /*ctx*/) override { }

  virtual void enterControl_statement(originirParser::Control_statementContext * /*ctx*/) override { }
  virtual void exitControl_statement(originirParser::Control_statementContext * /*ctx*/) override { }

  virtual void enterQelse_statement_fragment(originirParser::Qelse_statement_fragmentContext * /*ctx*/) override { }
  virtual void exitQelse_statement_fragment(originirParser::Qelse_statement_fragmentContext * /*ctx*/) override { }

  virtual void enterQif_if(originirParser::Qif_ifContext * /*ctx*/) override { }
  virtual void exitQif_if(originirParser::Qif_ifContext * /*ctx*/) override { }

  virtual void enterQif_ifelse(originirParser::Qif_ifelseContext * /*ctx*/) override { }
  virtual void exitQif_ifelse(originirParser::Qif_ifelseContext * /*ctx*/) override { }

  virtual void enterQwhile_statement(originirParser::Qwhile_statementContext * /*ctx*/) override { }
  virtual void exitQwhile_statement(originirParser::Qwhile_statementContext * /*ctx*/) override { }

  virtual void enterMeasure_statement(originirParser::Measure_statementContext * /*ctx*/) override { }
  virtual void exitMeasure_statement(originirParser::Measure_statementContext * /*ctx*/) override { }

  virtual void enterReset_statement(originirParser::Reset_statementContext * /*ctx*/) override { }
  virtual void exitReset_statement(originirParser::Reset_statementContext * /*ctx*/) override { }

  virtual void enterBarrier_statement(originirParser::Barrier_statementContext * /*ctx*/) override { }
  virtual void exitBarrier_statement(originirParser::Barrier_statementContext * /*ctx*/) override { }

  virtual void enterExpression_statement(originirParser::Expression_statementContext * /*ctx*/) override { }
  virtual void exitExpression_statement(originirParser::Expression_statementContext * /*ctx*/) override { }

  virtual void enterDefine_gate_statement(originirParser::Define_gate_statementContext * /*ctx*/) override { }
  virtual void exitDefine_gate_statement(originirParser::Define_gate_statementContext * /*ctx*/) override { }

  virtual void enterDefine_dagger_statement(originirParser::Define_dagger_statementContext * /*ctx*/) override { }
  virtual void exitDefine_dagger_statement(originirParser::Define_dagger_statementContext * /*ctx*/) override { }

  virtual void enterDefine_control_statement(originirParser::Define_control_statementContext * /*ctx*/) override { }
  virtual void exitDefine_control_statement(originirParser::Define_control_statementContext * /*ctx*/) override { }

  virtual void enterUser_defined_gate(originirParser::User_defined_gateContext * /*ctx*/) override { }
  virtual void exitUser_defined_gate(originirParser::User_defined_gateContext * /*ctx*/) override { }

  virtual void enterExplist(originirParser::ExplistContext * /*ctx*/) override { }
  virtual void exitExplist(originirParser::ExplistContext * /*ctx*/) override { }

  virtual void enterExp(originirParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(originirParser::ExpContext * /*ctx*/) override { }

  virtual void enterGate_func_statement(originirParser::Gate_func_statementContext * /*ctx*/) override { }
  virtual void exitGate_func_statement(originirParser::Gate_func_statementContext * /*ctx*/) override { }

  virtual void enterId(originirParser::IdContext * /*ctx*/) override { }
  virtual void exitId(originirParser::IdContext * /*ctx*/) override { }

  virtual void enterId_list(originirParser::Id_listContext * /*ctx*/) override { }
  virtual void exitId_list(originirParser::Id_listContext * /*ctx*/) override { }

  virtual void enterGate_name(originirParser::Gate_nameContext * /*ctx*/) override { }
  virtual void exitGate_name(originirParser::Gate_nameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

