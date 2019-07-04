type action =
  | Change(string)
  | Clear;

[@react.component]
let make = (~addPoke, ~isAddDisabled) => {
  let (value, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Change(payload) => payload
        | Clear => ""
        },
      "",
    );

  <div>
    <input
      placeholder="Placeholder..."
      onChange={event =>
        dispatch(Change(ReactEvent.Form.target(event)##value))
      }
      value
    />
    <button
      disabled=isAddDisabled
      onClick={_event => {
        addPoke(value);
        dispatch(Clear);
      }}>
      {ReasonReact.string("Add")}
    </button>
  </div>;
};