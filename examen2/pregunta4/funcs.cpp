#include "funcs.hpp"

// Como mi carnet es 1610400 => X=4, Y=0, Z=0
ll alpha = 7, beta = 3;

// Implementacion como traduccion directa
ll fibo1(ll n){ 
	if( n<alpha*beta ) return n;
	ll ans = 0;
	FOR(i,1,alpha+1) ans += fibo1( n-beta*i );
	return ans;
}

// Implementacion como recursion de cola
ll fibo2( ll n ){
	if( n<alpha*beta ) return n;
	auto f = [&](auto &&f, ll f1, ll f2, ll f3, ll f4, ll f5, ll f6, ll f7, ll i) { 
		if( i==0 ) return f7;
        return f( f, f2, f3, f4, f5, f6, f7, f1+f2+f3+f4+f5+f6+f7, i-1 );
    }; 
    return f(f, 0+(n%beta), 3+(n%beta), 6+(n%beta), 9+(n%beta), 12+(n%beta), 15+(n%beta), 18+(n%beta),  (n-alpha*beta)/beta+1 );
}

// Implementacion iterativa
ll fibo3( ll n ){
	if( n<alpha*beta ) return n; 
	ll f[alpha], S = 0, prev;
	// esto corresponde a la primera llamada recursiva de f en fibo2
	FOR(i,0,alpha) f[i] = i*beta + (n%beta), S+=f[i]; 
	
	// ultimo parametro de la llamada de cola de f en fibo2
	FOR(it,0,(n-alpha*beta)/beta+1){ 
		prev = f[0];
		FOR(i,0,alpha-1) f[i] = f[i+1];
		f[alpha-1] = S; 
		S += (f[alpha-1]-prev);
	} 
	// caso base de f en fibo2
	return f[alpha-1]; 
}
