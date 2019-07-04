type action =
  | AddPoke(string)
  | RemovePoke(string);

[@react.component]
let make = () => {
  let (pokemons, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddPoke(payload) => [payload, ...state]
        | RemovePoke(payload) => List.filter(poke => poke !== payload, state)
        },
      [],
    );

  let addPoke = poke => dispatch(AddPoke(poke));

  <div>
    <Header> {ReasonReact.string("Header!")} </Header>
    <Search addPoke isAddDisabled={List.length(pokemons) >= 6} />
    {ReasonReact.array(
       Array.of_list(
         List.map(
           poke =>
             <div>
               {ReasonReact.string(poke)}
               <button onClick={_event => dispatch(RemovePoke(poke))}>
                 {ReasonReact.string("Remove")}
               </button>
             </div>,
           pokemons,
         ),
       ),
     )}
  </div>;
};