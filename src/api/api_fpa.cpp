/*++
Copyright (c) 2013 Microsoft Corporation

Module Name:

    api_fpa.cpp

Abstract:


Author:

    Christoph M. Wintersteiger (cwinter) 2013-06-05

Notes:
    
--*/
#include<iostream>
#include"z3.h"
#include"api_log_macros.h"
#include"api_context.h"
#include"float_decl_plugin.h"

extern "C" {

    Z3_sort Z3_API Z3_mk_fpa_rounding_mode_sort(Z3_context c) {
        Z3_TRY;
        LOG_Z3_mk_fpa_rounding_mode_sort(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);        
        Z3_sort r = of_sort(ctx->float_util().mk_rm_sort());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }   

    Z3_ast Z3_API Z3_mk_fpa_round_nearest_ties_to_even(Z3_context c)
    {
        Z3_TRY;
        LOG_Z3_mk_fpa_round_nearest_ties_to_even(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_round_nearest_ties_to_even());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_round_nearest_ties_to_away(Z3_context c)
    {
        Z3_TRY;
        LOG_Z3_mk_fpa_round_nearest_ties_to_even(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_round_nearest_ties_to_away());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_round_toward_positive(Z3_context c)
    {
        Z3_TRY;
        LOG_Z3_mk_fpa_round_nearest_ties_to_even(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_round_toward_positive());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_round_toward_negative(Z3_context c)
    {
        Z3_TRY;
        LOG_Z3_mk_fpa_round_nearest_ties_to_even(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_round_toward_negative());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_round_toward_zero(Z3_context c)
    {
        Z3_TRY;
        LOG_Z3_mk_fpa_round_nearest_ties_to_even(c);
        RESET_ERROR_CODE(); 
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_round_toward_zero());
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }


    Z3_sort Z3_API Z3_mk_fpa_sort(Z3_context c, unsigned ebits, unsigned sbits) {
        Z3_TRY;
        LOG_Z3_mk_fpa_sort(c, ebits, sbits);
        RESET_ERROR_CODE(); 
        if (ebits < 2 || sbits < 3) {
            SET_ERROR_CODE(Z3_INVALID_ARG);
        }        
        api::context * ctx = mk_c(c);        
        Z3_sort r = of_sort(ctx->float_util().mk_float_sort(ebits, sbits));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_half(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 5, 11);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_16(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 5, 11);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_single(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 8, 24);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_32(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 8, 24);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_double(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 11, 53);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_64(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 11, 53);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_quadruple(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 15, 113);
    }

    Z3_sort Z3_API Z3_mk_fpa_sort_128(__in Z3_context c) {
        return Z3_mk_fpa_sort(c, 15, 113);
    }

    Z3_ast Z3_API Z3_mk_fpa_nan(Z3_context c, Z3_sort s) {
        Z3_TRY;
        LOG_Z3_mk_fpa_nan(c, s);
        RESET_ERROR_CODE();         
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_nan(to_sort(s)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
    
    Z3_ast Z3_API Z3_mk_fpa_inf(Z3_context c, Z3_sort s, Z3_bool negative) {
        Z3_TRY;
        LOG_Z3_mk_fpa_inf(c, s, negative);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(negative != 0 ? ctx->float_util().mk_minus_inf(to_sort(s)) : ctx->float_util().mk_plus_inf(to_sort(s)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_zero(Z3_context c, Z3_sort s, Z3_bool negative) {
        Z3_TRY;
        LOG_Z3_mk_fpa_inf(c, s, negative);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(negative != 0 ? ctx->float_util().mk_nzero(to_sort(s)) : ctx->float_util().mk_pzero(to_sort(s)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_numeral_double(Z3_context c, double v, Z3_sort ty) {
        Z3_TRY;
        LOG_Z3_mk_fpa_numeral_double(c, v, ty);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        scoped_mpf tmp(ctx->float_util().fm());
        ctx->float_util().fm().set(tmp, ctx->float_util().get_ebits(to_sort(ty)), ctx->float_util().get_sbits(to_sort(ty)), v);
        Z3_ast r = of_ast(ctx->float_util().mk_value(tmp));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
    
    Z3_ast Z3_API Z3_mk_fpa_abs(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_abs(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_abs(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_neg(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_neg(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_neg(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_add(Z3_context c, Z3_ast rm, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_add(c, rm, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_add(to_expr(rm), to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_sub(Z3_context c, Z3_ast rm, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_add(c, rm, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_sub(to_expr(rm), to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_mul(Z3_context c, Z3_ast rm, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_add(c, rm, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_mul(to_expr(rm), to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_div(Z3_context c, Z3_ast rm, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_add(c, rm, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_div(to_expr(rm), to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_fma(Z3_context c, Z3_ast rm, Z3_ast t1, Z3_ast t2, Z3_ast t3) {
        Z3_TRY;
        LOG_Z3_mk_fpa_fma(c, rm, t1, t2, t3);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_fma(to_expr(rm), to_expr(t1), to_expr(t2), to_expr(t3)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_sqrt(Z3_context c, Z3_ast rm, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_sqrt(c, rm, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_sqrt(to_expr(rm), to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_rem(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_rem(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_rem(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_eq(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_eq(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_float_eq(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_le(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_le(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_le(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_lt(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_lt(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_lt(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
    
    Z3_ast Z3_API Z3_mk_fpa_ge(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_ge(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_ge(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_gt(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_gt(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_gt(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_is_normal(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_is_normal(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_is_normal(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_is_subnormal(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_is_subnormal(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_is_subnormal(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_is_zero(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_is_zero(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_is_zero(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_is_inf(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_is_inf(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_is_inf(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_is_nan(Z3_context c, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_is_nan(c, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_is_nan(to_expr(t)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_min(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_min(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_min(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
   
    Z3_ast Z3_API Z3_mk_fpa_max(Z3_context c, Z3_ast t1, Z3_ast t2) {
        Z3_TRY;
        LOG_Z3_mk_fpa_max(c, t1, t2);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        Z3_ast r = of_ast(ctx->float_util().mk_max(to_expr(t1), to_expr(t2)));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }

    Z3_ast Z3_API Z3_mk_fpa_convert(Z3_context c, Z3_sort s, Z3_ast rm, Z3_ast t) {
        Z3_TRY;
        LOG_Z3_mk_fpa_convert(c, s, rm, t);
        RESET_ERROR_CODE();
        api::context * ctx = mk_c(c);
        expr * args [2] = { to_expr(rm), to_expr(t) };
        Z3_ast r = of_ast(ctx->m().mk_app(ctx->float_util().get_family_id(), OP_FLOAT_TO_FP, 
                                          to_sort(s)->get_num_parameters(), to_sort(s)->get_parameters(),
                                          2, args));
        RETURN_Z3(r);
        Z3_CATCH_RETURN(0);
    }
};
