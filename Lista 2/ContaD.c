int faz_conta_direito(int parcelas, char op){
    int valor[parcelas];
    int result=0;
    
    if(op == '+'){
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &valor[i]);
            result += valor[i];
        }
    }

    if(op == '-'){
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &valor[i]);
            result -= valor[i];
            
        }
        result = result + 2*valor[0];
    }

    return result;

}
